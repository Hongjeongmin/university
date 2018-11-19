<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%@ page import="java.util.*,java.text.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form method = "post" action="vote_update.jsp">
	
	투표를 해주세요!<p>
	<input type="radio" name="star" value="IU"/>IU <br>
	<input type="radio" name="star" value="GD"/>GD <br>
	<input type="radio" name="star" value="TOP"/>TOP <br>
	<input type="submit"value="제출"/>
	</form>
</body>
</html>