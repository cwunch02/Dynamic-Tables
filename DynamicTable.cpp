
#include "DynamicTable.h"

void DynamicTable::insert(int value, bool dummy_version) {

    //add a new element in the table
    //use `dummy_version` to decide which version of resize you want to call

    if(size != last){
        table[last] = value;
        last++;
    } else {
        if (dummy_version) {
            resize_dummy();
            table[last] = value;
            last++;
        } else {
            resize();
            table[last] = value;
            last++;
        }
    }

}

void DynamicTable::resize_dummy() {
    n_resize_called++;

    int *newTable;

    newTable = new int[size+1];
    for(int x = 0; x < size; x++){
        newTable[x] = table[x];
    }
    delete[] table;
    table = newTable;
    size++;
    return;
}

void DynamicTable::resize() {
    n_resize_called++;

    //resize the table when necessary doubling its size

    int *newTable;

    newTable = new int[size*2];
    for(int x = 0; x < size; x++){
        newTable[x] = table[x];
    }
    delete[] table;
    table = newTable;
    size*=2;
    return;

}