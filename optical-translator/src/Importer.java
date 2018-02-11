import java.io.*;
import java.lang.reflect.Array;
import java.util.Scanner;

public class Importer {

    public String getFilePath(String fileName){
        String filePath = System.getProperty("user.dir") + "/" + fileName;
        return filePath;
    }

    public int getFileLength(String filePath){
        int lineNumber = 0;
        try {
            FileReader fr = new FileReader(filePath);
            LineNumberReader lnr = new LineNumberReader(fr);
            while(lnr.readLine() != null){
                lineNumber++;
            }
            System.out.println("Number of Lines: "+lineNumber);
            lnr.close();
            return lineNumber;
        }
        catch(IOException e){
           // e.printStackTrace();
        }
        return lineNumber;
    }

    public void read(String filePath){
        String out;
        int length = getFileLength(filePath);
        String line = "";
        for(int i=0;i<=length;i++){
            try {
                BufferedReader reader = new BufferedReader(new FileReader(filePath));
                line = reader.readLine();
                System.out.println("Read Line "+i+": "+line);
            } catch (IOException x) {
                //x.printStackTrace(new PrintStream(System.out));
                System.out.println("ERROR READING LINE");
            }
        }
        //return out;
    }

    /*public Array[][] parse(){

    }*/

    public Importer(){

    }

    public static void main(String[] args){
        Importer a = new Importer();
        System.out.println("Insert name of html file to import (must be in the mascot-testing directory):");
        Scanner in = new Scanner(System.in);
        String fileNameIn = in.nextLine();
        System.out.println("Input file: " + fileNameIn);
        System.out.println(System.getProperty("user.dir"));
        String filePath=a.getFilePath(fileNameIn);

        a.read(filePath);

    }
}
