<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<% 
int i = Integer.parseInt(request.getParameter("delno_n"));
ArrayList<String> arr = (ArrayList<String>)session.getAttribute("car_s");
arr.remove(i);
session.setAttribute("car_s",arr);
response.sendRedirect("jang.jsp");
%>