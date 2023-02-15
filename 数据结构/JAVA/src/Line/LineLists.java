package Line;

/**
 *
 */
public interface LineLists<E>{
    static final int ELEMENT_NOT_EXISTS=-1;
    int size();
    boolean isEmpty();
    void clear();
    void add(E element);
    void add(int index,E element);
    E remove();
    E remove(int index);
    void set(int index,E element);
    void set(E e1,E e2);
    E get(int index);
    int indexOf(E element);
    boolean contains(E element);
}
