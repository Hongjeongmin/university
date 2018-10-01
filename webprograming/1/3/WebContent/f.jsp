<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%! 
String dd = "다람쥐";
public String getMethod(){return dd;}	
%>
<%
String ss = "냐옹이"; String cc = "수박";
/* 하늘이 파랗네요~*/
out.print("dd");
%>
바다도 파랗네요 ~<br>와~
<%= ss + cc %><br>
/* 강도 파랗거든 */
*/ 시냇물은? /*
<%=getMethod() %><br>
//
<!-- 나 헝그리~ -->
<%-- 너도 헝그리~ --%>

배고파
</body>
</html>