package Line;

/**
 *
 */
public class stack <E> {
    private Arrays<E> sta;
    public void push(E element){
        sta.add(element);
    }
    public E pop(){
        return sta.remove();
    }
    public E head(){
        return sta.get(sta.size()-1);
    }
    public void clear(){
        sta.clear();
    }
    public int size(){
        return sta.size();
    }
    public boolean isEmpty(){
        return sta.isEmpty();
    }
}
