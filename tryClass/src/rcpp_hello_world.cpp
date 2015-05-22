
#include <Rcpp.h>

#include "SamData.hpp"
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
    SamData d;
    d.setId(18);
    return Rcpp::wrap(d);
}

// [[Rcpp::export]]
long samId(SEXP s) {
    SamData d = Rcpp::as<SamData>(s);
    long id = d.getId();
    
    return id;
}
