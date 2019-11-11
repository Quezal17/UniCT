
public class TestFile {

	public static void main(String[] args) {
		
		Resource fold1 = Creator.getFolder();
		Resource img1 = Creator.getImage();
		
		fold1.add(img1);
		
		Resource fold2=Creator.getFolder();
		Resource img2=Creator.getImage();
		Resource img3=Creator.getImage();
		
		fold2.add(img2);
		fold2.add(img3);
		fold1.add(fold2);
		
		fold1.show();
	}

}
