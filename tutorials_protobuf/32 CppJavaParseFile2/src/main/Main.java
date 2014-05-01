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

import proto.EmployeeData.Employee;
import proto.A;

// class A {
// 	public int a=65;
// 	public class B {
// 		public int b=66;
// 	}
// }

public class Main {
	public static void main(String[] args) {
		
		String data_file = "../employee_data.dat";
		if (args.length != 1) {
			System.out.println("Usage: java main.Main <data file>");
			System.out.println("<data file> parameter missing.. ");
			System.out.println("Continuing the program with data file as \'../data.dat\'");
		}
		
		// FileOutputStream fo = null;
		// // Serialize to file
		// try {
		// 	fo = new FileOutputStream(new File(data_file));
		// 	Data.Builder t = Data.newBuilder();
		// 	t.setF(1233.37f);
		// 	t.build().writeTo(fo);
		// } catch (FileNotFoundException e1) {
		// 	// TODO Auto-generated catch block
		// 	e1.printStackTrace();
		// } catch (IOException e) {
		// 	// TODO Auto-generated catch block
		// 	e.printStackTrace();
		// } finally {
		// 	try {
		// 		fo.close();
		// 	} catch (IOException e) {
		// 		// TODO Auto-generated catch block
		// 		e.printStackTrace();
		// 	}
		// }

		// Parse from file
		FileInputStream fi = null;
		try {
			fi = new FileInputStream(new File(data_file));
			Employee.Builder emp = Employee.newBuilder();
			emp.mergeFrom(fi);
			System.out.println("Parsed data: ");
			if (emp.hasEmpId()) 	{ System.out.print("\t ID      : "); System.out.println(emp.getEmpId()); }
			if (emp.hasEmpName()) 	{ System.out.print("\t ID      : "); System.out.println(emp.getEmpName()); }
			for (Employee.PhoneNumber phone : emp.getPhoneNumberList()) {
				System.out.print("\t phone number : "); 
				System.out.print(phone.getType()); 
				System.out.print("(type) ");
				System.out.print(phone.getNumber()); 
				System.out.println("(number) ");
			}

		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				fi.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}
}