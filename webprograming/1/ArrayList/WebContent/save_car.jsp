<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<%
request.setCharacterEncoding("UTF-8");
String[] car = request.getParameterValues("car_n"); // 앞에서 선택한 차들
if(car != null) {
ArrayList<String> arr = (ArrayList<String>)session.getAttribute("car_s");
for(String s:car) {
arr.add(s);
}
session.setAttribute("car_s", arr);
}
response.sendRedirect("jang.jsp");
%>