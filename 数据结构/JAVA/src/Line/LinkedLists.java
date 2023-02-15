package Line;

/**
 *
 */
public class LinkedLists <E> extends abstractLists<E>{
    protected static class bases_node<E>{
        E element;
        bases_node<E> next;
        public bases_node(E element, bases_node<E> next) {
            this.element = element;
            this.next = next;
        }

        @Override
        public String toString() {
            return element+"->"+(this.next==null?"null":this.next.element);
        }
    }
    private bases_node<E> first;
    @Override
    public void add(int index, E element) {
        if(index==0){
            this.first=new bases_node<>(element,this.first);
        }else{
            bases_node<E> node = node(index - 1);
            node.next=new bases_node<>(element,node.next);
        }
        this.size++;
    }

    private bases_node<E> node(int index){
        rangeCheckIndex(index);
        bases_node<E> node = this.first;
        for (int i = 0; i < index; i++) {
            node=node.next;
        }
        return node;
    }

    @Override
    public E remove(int index) {
        E old=get(index);
        if (index==0){
            this.first=this.first.next;
        }else{
            bases_node<E> node = node(index - 1);
            node.next=node.next.next;
        }
        this.size--;
        return old;
    }

    @Override
    public void set(int index, E element) {
        node(index).element=element;
    }

    @Override
    public void set(E e1, E e2) {
        node(indexOf(e1)).element=e2;
    }

    @Override
    public E get(int index) {
        return node(index).element;
    }

    @Override
    public int indexOf(E element) {
        bases_node<E> node = this.first;
        if (element==null){
            for (int i = 0; i < size; i++,node=node.next) {
                if (node.element==null)
                    return i;
            }
        }else{
            for (int i = 0; i < size; i++,node=node.next) {
                if (node.element.equals(element))
                    return i;
            }
        }
        return ELEMENT_NOT_EXISTS;
    }

    @Override
    protected String getString(int index) {
        return node(index).toString();
    }
}
