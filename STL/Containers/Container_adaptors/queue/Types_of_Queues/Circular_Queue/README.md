# Introduction to Circular Queue

## What is a Circular Queue?
A Circular Queue is an extended version of a normal queue where the last element of the queue is connected to the first element of the queue forming a circle.

The operations are performed based on FIFO (First In First Out) principle. It is also called ‘Ring Buffer’. 
![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/ba091b3d-d8b7-46f4-8c2c-1481223538d2)

In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we can not insert the next element even if there is a space in front of queue.

## Operations on Circular Queue:
- Front: Get the front item from the queue.
- Rear: Get the last item from the queue.
- enQueue(value) This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at the rear position. 
  - Check whether the queue is full – [i.e., the rear end is in just before the front end in a circular manner].
  - If it is full then display Queue is full. 
      - If the queue is not full then,  insert an element at the end of the queue.
- deQueue() This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from the front position. 
  - Check whether the queue is Empty.
  - If it is empty then display Queue is empty.
    - If the queue is not empty, then get the last element and remove it from the queue.
   
![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/1798e054-ee3e-4c52-b650-b67f6f569a7c)

