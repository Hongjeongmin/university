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
	String w4 = request.getParameter("w3");
	
%>
<h3>�����!</h3>
<img src = "D:\photo\1107��������\<%= w4 %>.jpg" width=400px height =580px >

</body>
</html>