<%@ page language="java" contentType="text/html;
charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<%
ArrayList<String> arr = new ArrayList<String>();
session.setAttribute("arr",arr);
response.sendRedirect("c.jsp");
%>