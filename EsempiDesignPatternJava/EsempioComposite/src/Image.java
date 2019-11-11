
public class Image extends Resource {
	 private int x, y;
	 private String name;
	 public Image(String id, int a, int b){
	 name = id; x = a; y = b;
	 }
	 @Override
	 public void show() {
		 System.out.println("Image "+name+" ("+x+","+y+")");
	 }
}
