package Tree;

import java.util.Comparator;

/**
 *
 */
public abstract class BinTree <E> implements Tree<E>{
    protected Comparator<E> comparator;

    public BinTree() {
        this(null);
    }

    public BinTree(Comparator<E> comparator) {
        this.comparator = comparator;
    }

    protected int size;
    protected static class Base_Node<E>{
        E element;
        Base_Node<E>left;
        Base_Node<E> right;
        Base_Node<E> parent;

        public Base_Node(E element, Base_Node<E> parent) {
            this.element = element;
            this.parent = parent;
        }
    }
    protected Base_Node<E> root;
    protected int Compare(E e1,E e2){
        if (comparator!=null){
           return comparator.compare(e1, e2);
        }else{
            return ((Comparable<E>)e1).compareTo(e2);
        }
    }
    protected abstract Base_Node<E> createNode(E element, Base_Node<E> parent);
    @Override
    public abstract void add(E element);

    @Override
    public abstract void remove(E element);

    @Override
    public abstract boolean contains(E element);

    @Override
    public int size() {
        return this.size;
    }

    @Override
    public void clear() {
        this.size=0;
        this.root=null;
    }

    @Override
    public boolean isEmpty() {
        return this.size==0;
    }
    protected static abstract class Visitor<E>{
        boolean flag=false;
        abstract boolean visit(Base_Node<E> node);
    }
    public void prevOrder(Visitor<E> visit){
        if (visit==null)
            return ;
        prevOrder(root,visit);
    }
    protected void prevOrder(Base_Node<E> node,Visitor<E> visit){
        if (node==null|| visit.flag)
            return;
        visit.flag= visit.visit(node);
        prevOrder(node.left,visit);
        prevOrder(node.right,visit);
    }
    public void midOrder(Visitor<E> visit){
        if (visit==null)
            return ;
        midOrder(root,visit);
    }
    protected void midOrder(Base_Node<E> node,Visitor<E> visit){
        if (node==null|| visit.flag)
            return;
        midOrder(node.left,visit);
        visit.flag= visit.visit(node);
        midOrder(node.right,visit);
    }
}
