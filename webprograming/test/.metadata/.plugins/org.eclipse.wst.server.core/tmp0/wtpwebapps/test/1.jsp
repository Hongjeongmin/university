<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<%!
		int one;
		int two =1;
		public int plusMethod(){
			return one + two;
		}
		String msg;
		int three;
	%>
	<%
		out.print("one 와 tow의 합은 ?"+ plusMethod()+"<p>");
		out.print("String msg의 값은 ?" + msg+"<p>");
		out.print("int three의 값은 ?" + three+"<p>");
	%>

</head>
<body>

</body>
</html>