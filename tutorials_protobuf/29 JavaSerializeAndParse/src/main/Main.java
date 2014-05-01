package main;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;

import proto.TestData.Data;


public class Main {
	public static void main(String[] args) {
		
		Data.Builder t = Data.newBuilder();
		// Data.Builder t = Data.newBuilder();
		t.setF(1233.37f);
		
		ByteArrayOutputStream o = new ByteArrayOutputStream();
		try {
			t.build().writeTo(o); 
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		Data.Builder t1 = Data.newBuilder();
		
		try {
			t1.mergeFrom(o.toByteArray());
			System.out.println(t1.getF());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}