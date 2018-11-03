<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import="java.sql.*"%>
<%
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql = 
"insert into member values('냥냥냥','nyang','9949','nyang@donga.ac.kr','010-8113-3124',0)";
try {
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection conn = DriverManager.getConnection(url, uid, pass);
Statement stmt = conn.createStatement();   // (3c)
stmt.executeUpdate(sql); // insert니까 executeUpdate(4U)
out.print("<h3>회원 가입 성공 </h3>");
out.print("<a href='select.jsp'>회원 전체 목록 보기</a>");
} catch (Exception e) {
out.print("죄송합니다. 시스템상 문제가 생겼어요 <br>" + e.getMessage());
}
%>
