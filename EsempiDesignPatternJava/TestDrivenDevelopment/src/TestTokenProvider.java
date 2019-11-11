
public class TestTokenProvider {
	private TokenProvider tp;
	public static void main(String[] args) {
		TestTokenProvider t=new TestTokenProvider();
		
		t.testLunghezza();
		t.testSet();
		t.testConsecutivi();
		t.testGetNext();
	}

	private void testLunghezza() {
		tp=new TokenProvider();
		
		String token=tp.getToken();
		if(token.length()==5) {
			System.out.println("test lunghezza OK");
		}else {
			System.out.println("test lunghezza NO");
		}
	}
	
	private void testSet() {
		tp=new TokenProvider();
		
		String token=tp.getToken();
		
		String charSet="123ABC";
		
		for(int i=0;i<token.length();i++)
		{
			if(!charSet.contains(token.charAt(i)+"")) {
				System.out.println("testSet NO");
				return;
			}
		}
		System.out.println("testSet OK");
	}
	
	private void testConsecutivi() {
		tp=new TokenProvider();
		
		String token1=tp.getToken();
		String token2=tp.getToken();
		
		if(token1.equals(token2)) {
			System.out.println("test consecutivo OK");
		}else{
		System.out.println("test consecutivo NO");
		}
	}
	
	private void testGetNext() {
		tp=new TokenProvider();
		
		
	}
}
