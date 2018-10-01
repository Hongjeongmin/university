<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%
	String iam = request.getParameter("iam");
	String color = request.getParameter("color");
%>
.... carrot.jsp 시작<p>
<%= iam %> <p>
<%= color %> <p>
.... carrot.jsp 끝<p>
</body>

</html>