package Tree;

/**
 *
 */
public interface Tree <E>{
    void add(E element);
    void remove(E element);
    boolean contains(E element);
    int size();
    void clear();
    boolean isEmpty();
}
