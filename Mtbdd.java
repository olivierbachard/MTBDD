class Mtbdd
{
	private native void affiche();
	private native void initialisation();
	private native void test();

	static { 
		try {
			System.loadLibrary("mtbdd");
		}
		catch (UnsatisfiedLinkError e) {
			System.out.println(e);
			System.exit(1);
		}

	}

	public static void main(String args[]){
		
		Mtbdd mtbdd = new Mtbdd();
		
		
		mtbdd.affiche();
		mtbdd.initialisation();
		mtbdd.test();
		
	}

}
