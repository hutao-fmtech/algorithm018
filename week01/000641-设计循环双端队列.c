typedef struct {
	int *data;
	int size;
	int head;
	int tail;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque *myCircularDequeCreate(int k)
{
	MyCircularDeque *q = malloc(sizeof(MyCircularDeque));
	q->size = k + 1;
	q->data = malloc(sizeof(int) * q->size);
	q->head = 0;
	q->tail = 0;
	return q;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque *obj)
{
	if (obj->head == obj->tail) {
		return true;
	}

	return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque *obj)
{
	if (obj->head == ((obj->tail + 1) % obj->size)) {
		return true;
	}
	return false;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque *obj, int value)
{
	if (myCircularDequeIsFull(obj)) {
		return false;
	}

	obj->head = (obj->head + obj->size - 1) % obj->size;
	obj->data[obj->head] = value;
	return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque *obj, int value)
{
	if (myCircularDequeIsFull(obj)) {
		return false;
	}

	obj->data[obj->tail] = value;
	obj->tail = (obj->tail + 1) % obj->size;
	return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque *obj)
{
	if (myCircularDequeIsEmpty(obj)) {
		return false;
	}
	obj->head = (obj->head + 1) % obj->size;
	return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque *obj)
{
	if (myCircularDequeIsEmpty(obj)) {
		return false;
	}

	obj->tail = (obj->tail + obj->size - 1) % obj->size;
	return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque *obj)
{
	if (myCircularDequeIsEmpty(obj)) {
		return -1;
	}

	return obj->data[obj->head];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque *obj)
{
	if (myCircularDequeIsEmpty(obj)) {
		return -1;
	}

	return obj->data[(obj->tail + obj->size - 1) % obj->size];
}

void myCircularDequeFree(MyCircularDeque *obj)
{
	if (obj == NULL) {
		return;
	}

	if (obj->data) {
		free(obj->data);
	}

	free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/