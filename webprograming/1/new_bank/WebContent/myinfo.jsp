<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%request.setCharacterEncoding("UTF-8"); String id = (String)session.getAttribute("id");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql =  "select * from bankmember where id = '" + id + "'";
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection conn = DriverManager.getConnection(url, uid, pass);
Statement cre = conn.createStatement(); // 3c
ResultSet rs = cre.executeQuery(sql); // 3c니까 4번에 sql
rs.next();  // select이므로 5번 잊지 말고
%>
<body style="background-color:#F2F2F2">
<form  method="post" action="myinfo_update.jsp"><p>
<h4><font color="blue"><%=id%></font>님, 회원 정보를 수정하시겠습니까?</h4>
PW &nbsp;: <input type="text" name="pw" value="<%=rs.getString("pw")%>"/><p>
이름 : <input type="text" name="name" value="<%=rs.getString("name")%>"/><p>   
나이 : <input type="number" name="age" value="<%=rs.getString("age")%>"/> <p>
폰 &nbsp;&nbsp;&nbsp;: <input type="text" name="phone" value="<%=rs.getString("phone")%>"/><p>   
<a href="menu.jsp">메뉴로 돌아가기</a> &nbsp;&nbsp;&nbsp;  
<input type="submit" value="정보 수정">
</form>
</body>
<%} catch (Exception e) {
out.print("문제 발생ㅠ 고객센터로 연락주세요~ <p>" + e.getMessage());
}%>