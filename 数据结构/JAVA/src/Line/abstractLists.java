package Line;

/**
 *
 */
public abstract class abstractLists<E> implements LineLists<E> {
    protected int size;

    @Override
    public int size() {
        return this.size;
    }

    @Override
    public boolean isEmpty() {
        return this.size==0;
    }

    @Override
    public void clear() {
        this.size=0;
    }

    @Override
    public void add(E element) {
        this.add(this.size,element);
    }

    @Override
    public abstract void add(int index, E element);

    @Override
    public E remove() {
        return this.remove(this.size-1);
    }

    @Override
    public abstract E remove(int index);

    @Override
    public abstract void set(int index, E element);

    @Override
    public abstract void set(E e1, E e2);

    @Override
    public abstract E get(int index);

    @Override
    public abstract int indexOf(E element);

    @Override
    public boolean contains(E element) {
        return this.indexOf(element)!=-1;
    }
    protected void rangeCheckIndex(int index){
        if(index<0||index>this.size)
            throw new OutOfMemoryError(index+">"+this.size);
    }
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("size:").append(this.size).append(", [");
        for (int i = 0; i < this.size; i++) {
            if (i!=0){
                stringBuilder.append(",");
            }
            stringBuilder.append(this.getString(i));
        }
        stringBuilder.append("]");
        return stringBuilder.toString();
    }

    protected abstract String getString(int index);
}
