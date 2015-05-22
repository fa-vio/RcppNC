
#ifndef SAMDATA_HPP_
#define SAMDATA_HPP_

class SamData {

private:
	std::string rowname, chr1, chr2, seq1; // file cols 1, 3, 7, 10
	size_t hs1, hs2;
	long id;
	long start1, start2; // file cols 4, 8

public:

	SamData() : hs1(0), hs2(0), id(-1), start1(0), start2(0) { }
	SamData(const SamData &s) { *this = s; }
	SamData(SamData&& o) : rowname(std::move(o.rowname)), chr1(std::move(o.chr1)), chr2(std::move(o.chr2)),
			seq1(std::move(o.seq1)), hs1(std::move(o.hs1)), hs2(std::move(o.hs2)), id(o.getId()),
			start1(std::move(o.start1)), start2(std::move(o.start2)) { }

	SamData& operator=(const SamData& s) = default;
	SamData& operator=(SamData&& s) = default;

	~SamData() { }

	// getters
	inline long getStart1() 		const { return start1; }
	inline long getStart2() 		const { return start2; }
	inline std::string getSeq() 	const { return seq1; }
	inline std::string getChr1()	const { return chr1; }
	inline std::string getChr2()	const { return chr2; }
	inline size_t getHS1() 			const { return hs1; }
	inline size_t getHS2()	 		const { return hs2; }
	inline long getId()				const { return id; }

	// setters
	void setRowname(std::string rn) { rowname = rn; }
	void setChr1(std::string chr1_) { chr1 = chr1_; }
	void setStart1(long st) 		{ start1 = st; }
	void setChr2(std::string chr2_) { chr2 = chr2_; }
	void setStart2(long st) 		{ start2 = st; }
	void setHS1(size_t h)			{ hs1 = h; }
	void setHS2(size_t h)			{ hs2 = h; }
	void setId(long l)				{ id = l; }
	void setSeq(std::string s)		{ seq1 = s; }

	// order sam data by chr1 - should consider start1 as well
	inline bool operator<(const SamData &sd) const {
		return (hs1 < sd.hs1) || (hs1 == sd.hs1 && start1 < sd.getStart1());
	}

	// needed to write an ordered SAM file, so that the parser does not
	// have to be modified. may be useful again
	friend std::ostream& operator<<(std::ostream &out, const SamData &sd) {
		out << sd.rowname 	<< "\t" <<
				sd.chr1 	<< "\t" <<
				sd.start1 	<< "\t" <<
				sd.chr2 	<< "\t" <<
				sd.start2 	<< "\t" <<
				sd.seq1;

		return out;
	}
};


//namespace Rcpp {
//    
//// define template specialisations for as and wrap
//template<> SEXP wrap(const SamData &s) {
//   return Rcpp::List::create( Rcpp::Named("Chr1") = s.getChr1(),
//                        Rcpp::Named("Chr2") = s.getChr2(),
//                        Rcpp::Named("Seq1") = s.getSeq(),
//                       Rcpp::Named("HS1")  = s.getHS1(),
//                        Rcpp::Named("HS2")  = s.getHS2(),
//                       Rcpp::Named("Id")   = s.getId(),
//                        Rcpp::Named("Start1") = s.getStart1(),
//                        Rcpp::Named("Start2") = s.getStart2() );
//    //return wrap(ret);
//}
//
//template <> SamData as( SEXP s ) {
//    List samL(s);
//    SamData sam;
//    sam.setChr1( Rcpp::as<std::string>(samL["Chr1"]) );
//    sam.setChr2( Rcpp::as<std::string>(samL["Chr2"]) );
//    sam.setSeq( Rcpp::as<std::string>(samL["Seq1"]) );
//    sam.setHS1( Rcpp::as<size_t>(samL["HS1"]) );
//    sam.setHS2( Rcpp::as<size_t>(samL["HS2"]) );
//    sam.setStart1( Rcpp::as<long>( samL["Start1"]) );
//    sam.setStart2( Rcpp::as<long>( samL["Start2"]) );
//    sam.setId( Rcpp::as<long>( samL["Id"]) );
//    
//    return sam;
//}

#endif
