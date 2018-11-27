<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<%
if (session.getAttribute("car_s") == null) {
ArrayList<String> arr = new ArrayList<String>(3);
session.setAttribute("car_s", arr);
}
%>
<body style="background-color:lime">
<h2>메뉴</h2>
<ul>
<li><a href = "car.jsp">람보르기니와 프라임</a></li>
<li><a href = "jang.jsp">장바구니</a></li>
<li><a href = "logout.jsp">logout</a></li>
</ul>
</body>