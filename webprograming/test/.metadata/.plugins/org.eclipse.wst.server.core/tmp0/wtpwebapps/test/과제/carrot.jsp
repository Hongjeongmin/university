<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	String iam = request.getParameter("iam");
	String color = request.getParameter("color");
%>
..... carrot.jsp 시작<p>
<%=iam %> <p>
<%=color %> <p>
...... carrot.jsp 끝 <p>
</body>
</html>