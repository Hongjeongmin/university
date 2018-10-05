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
	request.setCharacterEncoding("UTF-8");
	String[] foods = request.getParameterValues("foods");
%>
<font color="blue"><%= request.getParameter("age") %>세 <%= request.getParameter("gender") %></font>
<p>

좋아하는 음식:
<font color="blue"><% if(foods==null) {out.print("없음");} 
else {for(int i=0;i<foods.length;i++){ %>
	<%= foods[i] %><br>
<%}}%></font>
<p>
외모 자신감(1-5):<font color="blue"><%= request.getParameter("a") %></font><br>
학점 자신감(1-5):<font color="blue"><%= request.getParameter("b") %></font><br>
수업 이해도(1-5):<font color="blue"><%= request.getParameter("c") %></font><br>
<p>
의견:<br>
<font color="blue"><%= request.getParameter("comments") %></font>
</body>
</html>