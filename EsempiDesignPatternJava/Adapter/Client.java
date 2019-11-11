
public class Client {
	public static void main(String[] args) {
		Target t=new Adapter(10);
		
		t.request();
	}
}
