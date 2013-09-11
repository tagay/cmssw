#ifndef MuonAnalyzer_H
#define MuonAnalyzer_H


/** \class MuonAnalyzer
 *
 *  DQM muon analysis monitoring
 *
 *  \author G. Mila - INFN Torino
 */


#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h" 
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrajectorySeed/interface/TrajectorySeed.h"
#include "DataFormats/TrajectorySeed/interface/TrajectorySeedCollection.h"

#include "CommonTools/TriggerUtils/interface/GenericTriggerEventFlag.h"

class MuonEnergyDepositAnalyzer;
class MuonSeedsAnalyzer;
class MuonRecoAnalyzer;
class MuonKinVsEtaAnalyzer;
class SegmentTrackAnalyzer;
class MuonKinVsEtaAnalyzer;
class DiMuonHistograms;
class DQMStore;
class MuonServiceProxy;
class MuonRecoOneHLT;
class EfficiencyAnalyzer;

class MuonAnalyzer : public edm::EDAnalyzer {
 public:
  
  /// Constructor
  MuonAnalyzer(const edm::ParameterSet&);
  
  /// Destructor
  virtual ~MuonAnalyzer();
  
  /// Inizialize parameters for histo binning
  void beginJob(void);
  void beginRun(const edm::Run&, const edm::EventSetup&);

  /// Get the analysis
  void analyze(const edm::Event&, const edm::EventSetup&);

  /// Save the histos
  void endJob(void);
  void endRun(const edm::Run&, const edm::EventSetup&){};
  
 private:
  // ----------member data ---------------------------
  DQMStore* theDbe;
  edm::ParameterSet parameters;
  MuonServiceProxy *theService;
  // Switch for verbosity
  std::string metname;

  // Muon Label
  edm::EDGetTokenT<reco::MuonCollection>     theMuonCollectionLabel_;
  edm::EDGetTokenT<reco::TrackCollection>    theGlbMuTrackCollectionLabel_;
  edm::EDGetTokenT<reco::TrackCollection>    theStaMuTrackCollectionLabel_;
  edm::EDGetTokenT<TrajectorySeedCollection> theSeedsCollectionLabel_;
  edm::EDGetTokenT<edm::TriggerResults>      theTriggerResultsLabel_;

  bool theMuEnergyAnalyzerFlag;
  bool theSeedsAnalyzerFlag;
  bool theMuonRecoAnalyzerFlag;
  bool theMuonKinVsEtaAnalyzerFlag;
  bool theMuonSegmentsAnalyzerFlag;
  bool theDiMuonHistogramsFlag;
  bool theMuonRecoOneHLTAnalyzerFlag;
  bool theEfficiencyAnalyzerFlag;
 
  // Define Analysis Modules
  MuonEnergyDepositAnalyzer* theMuEnergyAnalyzer;
  MuonSeedsAnalyzer*         theSeedsAnalyzer;
  MuonRecoAnalyzer*          theMuonRecoAnalyzer;
  MuonKinVsEtaAnalyzer*      theMuonKinVsEtaAnalyzer;
  SegmentTrackAnalyzer*      theGlbMuonSegmentsAnalyzer;
  SegmentTrackAnalyzer*      theStaMuonSegmentsAnalyzer;
  DiMuonHistograms*          theDiMuonHistograms;
  MuonRecoOneHLT*            theMuonRecoOneHLTAnalyzer;
  EfficiencyAnalyzer*        theEfficiencyAnalyzer; 
};
#endif  
