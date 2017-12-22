#include "Allocator.h"
#include <iostream>
Allocator::Allocator(size_t size,size_t count):_size(size),_count(count) {
    _used_blocks = (char*)malloc(_size*_count);
    _free_blocks = (void**)malloc(sizeof(void*)*_count);
    for(size_t i=0;i<_count;i++) _free_blocks[i] = _used_blocks+i*_size;
    _free_count = _count;
    std::cout << "Allocator: Memory init" << std::endl;
}
void *Allocator::allocate() {
    void *result = nullptr;
    if(_free_count>0){
        result = _free_blocks[_free_count-1];
        _free_count--;
        std::cout << "Allocator: Allocate " << (_count-_free_count) <<" of " << _count << std::endl;
    }
    else{
        std::cout << "Allocator: No memory exception" <<std::endl;
    }
    return result;
}
void Allocator::deallocate(void *pointer) {
    std::cout << "Allocator: Deallocate"<< std::endl;
    _free_blocks[_free_count] = pointer;
    _free_count ++;
}
bool Allocator::has_free_blocks() {
    return _free_count>0;
}
Allocator::~Allocator() {
    if(_free_count<_count) std::cout << "Allocator: Memory leak" <<std::endl;
    else std::cout << "Allocator: Memory freed" <<std::endl;
    delete _free_blocks;
    delete _used_blocks;
}

