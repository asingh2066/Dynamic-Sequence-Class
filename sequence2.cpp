#include <cassert>
#include "sequence2.h"
#include <algorithm>
#include <cstdlib>

//Commented the resize and first part of insert and attatch function since the other functions are same from last project
// For some reason when running the test, test 8 outputs a random memory address, tried changing resize function but it did not help

namespace data_structures_assignment_3 {

    sequence::sequence(size_type initial_capacity) {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
        current_index = 0;
    };

    sequence::sequence(const sequence &source) {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        std::copy(source.data, source.data + used, data);
    }

    sequence::~sequence() {
        delete[] data;
    }

    sequence::value_type sequence::current() const{
        assert(is_item() == true);
        return data[current_index];
    }

    sequence::size_type sequence::size() const{
        return used;
    };

    void sequence::operator=(const sequence& source) {
        value_type *new_data;
        if (this == &source)
            return;

        if (capacity != source.capacity) {
            new_data = new value_type[source.capacity];
            data = new_data;
            capacity = source.capacity;
        }
        used = source.used;
        current_index = source.current_index;
        std::copy(source.data, source.data + used, data);
    }

    void sequence::resize(size_type new_capacity){            // Function is allowing user to resize the capacity of the sequence in insert and attach in this case
            value_type *array2;
            if (new_capacity == capacity)                     //It is testing to see if the allocated memory
                return;                                       // already has same space as capacity, if so it returns and does nothing
            if (new_capacity < used)                          // If the allocated memory is less then the used in the array,
                new_capacity = used;                          // then the allocated memory is set equal to the used, since it can not be less then the amount we are using
            array2 = new value_type[new_capacity];
            std::copy(data, data + used, array2);
            delete [ ] data;
            data = array2;
            capacity = new_capacity;
        }

    void sequence::start(){
        current_index = 0;
    }

    bool sequence::is_item() const{
        if(current_index < used){
            return true;
        }
        else{
            return false;
        }
    }

    void sequence::advance() {
        assert(is_item());
        if (current_index == used){
            current_index = 30;
        }
        else{
            current_index++;
        }
    }

    void sequence::insert(const value_type& entry){
        if(used == capacity)                             //Making sure that there is enough space to add the new item, this checks
            resize(used+1);                              // to see, that if the space being used is the same as the capacity, increased the capacity by one before inserting a value
        if(!(is_item()))                                   // this resize is allowing for the dynamic array to be automatically enlarged
            current_index = 0;
        for (size_type i = used; i > current_index; i--){
            data[i] = data[i - 1];
        }
        data[current_index] = entry;
        used++;
    }

    void sequence::attach(const value_type& entry){
        //assert(size() < capacity);
        if(used == capacity)                    // Testing for same thing as stated in the insert
           resize(used+1);
        if (!is_item())
            current_index = used - 1;
        else{
            for (size_type i = used; i > current_index + 1; --i)
                data[i] = data[i - 1];
        }
        current_index++;
        data[current_index] = entry;
        used++;

    }

    void sequence::remove_current(){
        assert(is_item());
        for (size_type i = current_index + 1; i < used; ++i)
            data[i - 1] = data[i];
        used--;
        if(used==0)
            current_index=used;
    }

}


//EXTRA CREDIT Only did number one

//void sequence::operator +=(const sequence& addend) {
//    if (used + addend.used > capacity)
//    resize(used + addend.used);
//    copy(addend.data, addend.data + addend.used, data + used);
//    used += addend.used;
//}

//sequence::sequence operator +(const sequence& s1, const sequence& s2){
//    sequence new_size(s1.size( ) + s2.size( ));
//    new_size = new_size + s1;
//    new_size = new_size + s2;
//    return new_size;
//}