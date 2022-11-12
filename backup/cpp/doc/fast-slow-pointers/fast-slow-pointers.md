# Fast Slow Pointers

## Application
### String
1. head-tail 
   1. 344. Reverse String
2. in-place remove element


### Array
1. Reverse array
2. 

### LinkList: 
1. is linked list cycle?
   1. 141 - Linked List Cycle
2. the entry of the cycle list
   1. 142 - Linked List Cycle II
3. Middle of linklist
4. Last X-th element
   1. 


### template 

```cpp

slow = head;
fast = head->next;

while(slow != fast) {
    slow = slow->next;  // move one by one
    fast = fast->next->next;  // jump two node
}
```
