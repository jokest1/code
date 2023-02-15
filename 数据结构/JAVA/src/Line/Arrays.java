package Line;

/**
 *
 */
public class Arrays<E> extends abstractLists<E>{
    protected E[] arrays;
    private int capacity;
    private static int DEFAULT_CAPACITY=10;

    public Arrays() {
        this(DEFAULT_CAPACITY);
    }

    public Arrays(int capacity) {
        this.capacity=capacity>DEFAULT_CAPACITY?capacity:DEFAULT_CAPACITY;
        this.size=0;
        this.arrays= (E[]) new Object[this.capacity];
    }

    @Override
    public void add(int index, E element) {
        rangeCheckIndex(index);
        rangeCheckCapacity();
        for (int i = this.size; i >index ; i--) {
            this.arrays[i]=this.arrays[i-1];
        }
        this.arrays[index]=element;
        this.size++;
    }

    private void rangeCheckCapacity() {
        if(capacity<this.size+1){
            this.capacity=(this.capacity+(this.capacity>>1));
            E[] temp= (E[]) new Object[this.capacity];
            for (int i = 0; i < this.size; i++) {
                temp[i]=this.arrays[i];
            }
            this.arrays=temp;
        }
    }

    @Override
    public E remove(int index) {
        E old=get(index);
        this.size--;
        for (int i = index; i < this.size; i++) {
            this.arrays[i]=this.arrays[i+1];
        }
        return old;
    }

    @Override
    public void set(int index, E element) {
        rangeCheckIndex(index);
        this.arrays[index]=element;
    }

    @Override
    public void set(E e1, E e2) {
        set(indexOf(e1),e2);
    }

    @Override
    public E get(int index) {
        rangeCheckIndex(index);
        return this.arrays[index];
    }

    @Override
    public int indexOf(E element) {
        if (element==null){
            for (int i = 0; i < this.size; i++) {
                if (this.arrays[i]==null)
                    return i;
            }
        }else {
            for (int i = 0; i < this.size; i++) {
                if (this.arrays[i].equals(element))
                    return i;
            }
        }
        return ELEMENT_NOT_EXISTS;
    }

    @Override
    protected String getString(int index) {
        return get(index).toString();
    }

}
