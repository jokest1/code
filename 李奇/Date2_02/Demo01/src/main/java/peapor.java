/**
 *
 */
public class peapor {
    private Integer age;
    private String name;

    public peapor(int age, String name) {
        this.age = age;
        this.name = name;
    }

    @Override
    public String toString() {
        return "peapor{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
