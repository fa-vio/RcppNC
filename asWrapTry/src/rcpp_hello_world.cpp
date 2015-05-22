
#include <cstdio>
#include <string>
#include <iostream>

#include "SamData.hpp"

#include <RcppCommon.h>
#include "samdataRcppWrapperDecl.h"
#include <Rcpp.h>
#include "samdataRcppWrapperDef.h"

using namespace Rcpp;


// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
List rcpp_hello_world() {

    CharacterVector x = CharacterVector::create( "foo", "bar" )  ;
    NumericVector y   = NumericVector::create( 0.0, 1.0 ) ;
    List z            = List::create( x, y ) ;

    return z ;
}

// [[Rcpp::export]]
SEXP try_wrap_samdata() {
    SamData sd;
    sd.setId(189);
    sd.setChr1("Fabio");
    sd.setChr2("oibaF");
    
    return Rcpp::wrap(sd);
}

// [[Rcpp::export]]
long samId(SEXP s) {
    SamData d = Rcpp::as<SamData>(s);
    long id = d.getId();
    return id;
}