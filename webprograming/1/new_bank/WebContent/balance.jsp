<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>잔액조회</title>
</head>
<body>
	<%
		String id = (String)session.getAttribute("id");
		
		String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
		String uid = "scott";  String pass = "tiger";  
		String sql =  "select * from banktrade where id = '" + id + "'";
		try{
		Class.forName("oracle.jdbc.driver.OracleDriver");
		Connection conn = DriverManager.getConnection(url, uid, pass);
		Statement  stmt = conn.createStatement();   
		ResultSet rs = stmt.executeQuery(sql);
	%>
	<table border="1">
	<tr><th>이름</th><th>날짜</th><th>입금</th><th>출금</th></tr>
	<%while (rs.next()) {%>
			<tr>
			<td><%=rs.getString("id")%> </td>
			<td><%=rs.getString("tradedate")%> </td>
			<td><%=rs.getInt("deposit")%> </td>
			<td><%=rs.getInt("withdraw")%> </td>
			</tr>
		<%}%>
	<%} catch (Exception e){
		out.print("죄송합니다. 시스템상 문제가 생겼어요 <br>" + e.getMessage());
	}%>	
	
	</table>
</body>
</html>