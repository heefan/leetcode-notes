# Fast Slow Pointers

### Application

1. Detect cycle


### template 

```cpp

slow = head;
fast = head->next;

while(slow != fast) {
    slow = slow->next;  // move one by one
    fast = fast->next->next;  // jump two node
}
```
