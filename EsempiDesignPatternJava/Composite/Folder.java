import java.util.LinkedList;
public class Folder extends Resource {
 private String name;
 private LinkedList<Resource> r =
 new LinkedList<Resource>();
 public Folder(String f) {
 name = f;
 }
 @Override
 public void show() {
	 System.out.println("#"+name);
 for (int i = 0; i<r.size(); i++)
 r.get(i).show();
 }
 @Override
 public void add(Resource c){
 r.add(c);
 }
}
