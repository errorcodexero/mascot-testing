import java.io.*;
import java.lang.reflect.Array;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
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
            System.out.println("Number of Lines: " + lineNumber);
            lnr.close();
            return lineNumber;
        }
        catch(IOException e){
           // e.printStackTrace();
        }
        return lineNumber;
    }

    static String readFile(String path, Charset encoding) {
        try{
            byte[] encoded = Files.readAllBytes(Paths.get(path));
            return new String(encoded, encoding);
        }catch(IOException ioe){
            System.out.println("ERROR READING FILE/FILE PATH");
        }
        return "";
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

        a.readFile(filePath,Charset.defaultCharset());

    }
}
