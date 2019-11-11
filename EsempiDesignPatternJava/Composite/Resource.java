
public abstract class Resource {
	public abstract void show();
	//add, remove not to be called on Leaf
	public void add(Resource c) { }
	public void remove(Resource c) { }
}
