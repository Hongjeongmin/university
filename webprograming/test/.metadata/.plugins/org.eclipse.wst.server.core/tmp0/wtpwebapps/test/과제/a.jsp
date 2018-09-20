<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<%
	request.setCharacterEncoding("UTF-8");
	String myname = request.getParameter("name");
	String mymemo = request.getParameter("memo");
%>
<title>Insert title here</title>
</head>
<body>
<h2>Who am i ...</h2><p>
<table border="1">
<tr>
<td>성명</td><td><%= myname %></td>
</tr>
<tr>
<td>메모</td><td><%= mymemo %></td>
</tr>

</table>


</body>
</html>