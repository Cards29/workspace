import java.sql.*;

public class R220041118_lab7 {
    public static void main(String[] args) {
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");

            Connection con = DriverManager.getConnection(
                    "jdbc:oracle:thin:@localhost:1521:xe", "Rahinur_220041118", "cse4308");

            Statement stmt = con.createStatement();


            // 2b
            String query_1 = "Select COUNT(*) FROM ACCOUNT";

            ResultSet rs1 = stmt.executeQuery(query_1);

            while (rs1.next()) {
                System.out.print("Total: " + rs1.getInt(1));
                System.out.println();
            }

            rs1.close();



            con.close();

            } catch (Exception e) {
                System.out.println(e);
            }
        }
}
