package Line;

/**
 *
 */
public class DoubleLinkedLists<E> extends abstractLists<E>{
    protected static class bases_node<E>{
        E element;
        bases_node<E> next;
        bases_node<E> prev;

        public bases_node( bases_node<E> prev,E element, bases_node<E> next) {
            this.element = element;
            this.next = next;
            this.prev = prev;
        }

        @Override
        public String toString() {
            return (this.prev==null?"null":this.prev.element)+"<-"+element+"->"+(this.next==null?"null":this.next.element);
        }
    }
    protected bases_node<E> first;
    protected bases_node<E> last;
    @Override
    public void add(int index, E element) {
        if (size==0){
            this.first=new bases_node<>(null,element,null);
            this.last=this.first;
        }else if(index==0){
            this.first.prev=new bases_node<>(null,element,this.first);
            this.first=this.first.prev;
        }else if(index==this.size){
            this.last.next=new bases_node<>(this.last,element,null);
            this.last=this.last.next;
        }else{
            bases_node<E> node = node(index);
            bases_node<E> prev = node.prev;
            prev.next=new bases_node<>(prev,element,node);
            node.prev=prev.next;
        }
        this.size++;
    }

    protected bases_node<E> node(int index) {
        bases_node<E> node=null;
        if (index<=(this.size>>1)){
            node = this.first;
            for (int i = 0; i < index; i++) {
                node=node.next;
            }
        }else{
            node = this.last;
            for (int i=size-1;i>index;i--){
                node=node.prev;
            }
        }
        return node;
    }

    @Override
    public E remove(int index) {
        E old = node(index).element;
        if(index==0){
            this.first=this.first.next;
            this.first.prev=null;
        }else if(index==this.size-1){
            this.last=this.last.prev;
            this.last.next=null;
        }else{
            bases_node<E> node =this.node(index);
            bases_node<E> prev = node.prev;
            bases_node<E> next = node.next;
            prev.next=next;
            next.prev=prev;
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
