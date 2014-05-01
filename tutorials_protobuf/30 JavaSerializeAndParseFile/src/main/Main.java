package main;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;

import proto.TestData.Data;
import proto.A;

// class A {
// 	public int a=65;
// 	public class B {
// 		public int b=66;
// 	}
// }

public class Main {
	public static void main(String[] args) {
		
		String data_file = "../data.dat";
		
		FileOutputStream fo = null;
		// Serialize to file
		try {
			fo = new FileOutputStream(new File(data_file));
			Data.Builder t = Data.newBuilder();
			t.setF(1233.37f);
			t.build().writeTo(fo);
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				fo.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		// Parse from file
		FileInputStream fi = null;
		try {
			fi = new FileInputStream(new File(data_file));
			Data.Builder t1 = Data.newBuilder();
			t1.mergeFrom(fi);
			System.out.println(t1.getF());
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				fo.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}
}