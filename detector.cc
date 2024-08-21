#include "detector.hh"

GammaSensitive::~GammaSensitive() {}

G4bool GammaSensitive::ProcessHits(G4Step* step, G4TouchableHistory*)
{
    G4double edep = step->GetTotalEnergyDeposit();
    HitAccu *newhit = new HitAccu();
    if (edep > 0) {
        newhit->AddEdep(edep);
    }

    hits->insert(newhit);

    return true;
}

inline void HitAccu::AddEdep(G4double nrg)
{
    edep+= nrg;
}

void GammaSensitive::Initialize(G4HCofThisEvent* HCE) {
    hits = new G4THitsCollection<HitAccu>(SensitiveDetectorName, "HitCollection");
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID("HitCollection");
    HCE->AddHitsCollection(hcID, hits);
}

void GammaSensitive::EndOfEvent(G4HCofThisEvent*) {
    G4double totalEdep = 0.0;

    for (size_t i = 0; i < hits->GetSize(); ++i) {
        HitAccu* hit = (*hits)[i];
        totalEdep += hit->edep;
    }

    G4cout << "Total Energy Deposition: " << totalEdep / CLHEP::MeV << " MeV" << G4endl;
}