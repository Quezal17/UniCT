import java.util.Random;

public class TokenProvider {	
	final int SIZE=5;
	final String charSet="123ABC";
	private Random r=new Random();
	
	public String getToken() {
		String token="";
		int index;
		for(int i=0;i<SIZE;i++) {
			index=r.nextInt();
			token+=charSet.charAt(index%charSet.length());
		}
		return token;
	}
}
