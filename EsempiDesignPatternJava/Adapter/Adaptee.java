
public class Adaptee {
	private int i;
	
	Adaptee(int i) {
		this.i=i;
	}
	
	public void specificRequest() {
		System.out.println(++i);
	}
}
