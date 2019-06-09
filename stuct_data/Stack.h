
#ifndef DD_STACK_H__
#define DD_STACK_H__

#define MIN_STACK_SIZE 4
#define GROW_FACTOR 2

template <class T>
class Stack {
public:
    Stack() {
        _value = new T[MIN_STACK_SIZE];
        _size = MIN_STACK_SIZE;
        _top = 0;
    }
    
    ~Stack() {
        delete[] _value;
        _value = NULL;
    }
    
    T top() {
        if (_top == 0)
            return NULL;
        return _value[_top - 1];
    }
    
    void pop() {
//        destroy(_value[_top - 1]);
        _top--;
    }
    
    void push(T value) {
        if (_top == _size - 1) {
            T *copy = new T[_size * GROW_FACTOR];
            if (copy == nullptr)
                throw;
            memcpy(copy, _value, _size * sizeof(T));
            delete[] _value;
            _value = copy;
            copy = NULL;
            _size *= 2;
        }
        _value[_top++] = value;
    }
    
    bool isEmpty() {
        return _top == 0;
    }
    
    void clear() {
        for (int i = 0; i < _top; ++i) {
//            if constexpr (std::is_pointer<T>::value)
//                delete (_value[i]);
        }
        _top = 0;
    }
    
    inline void destroy(T* pointer) {
        pointer->~T();
    }
    
private:
    int _top;
    int _size;
    T *_value;
    
};

#endif /* DD_STACK_H__ */
