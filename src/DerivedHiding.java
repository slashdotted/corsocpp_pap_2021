
public class DerivedHiding extends BaseHiding {
	public void f(int x) {
        System.out.println("derived::f");
    } 

    public static void main(String[] arg) {
		DerivedHiding e = new DerivedHiding();
		e.f(3.2);
		e.f(3);
	}      
}
