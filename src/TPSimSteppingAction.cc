/// TPSimSteppingAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimSteppingAction.hh"

using namespace CLHEP;

const G4String TPSimSteppingAction::path = "../simulation_input_files/";

TPSimSteppingAction::TPSimSteppingAction()
{
  sMessenger = new G4GenericMessenger(this, "/SteppingAction/", "Control commands for my application");

  sMessenger->DeclareProperty("SetVerbose", VerbosityLevel)
      .SetGuidance("Set the verbosity level.")
      .SetParameterName("VerbosityLevel", false)
      .SetDefaultValue("0");

  sMessenger->DeclareProperty("SetPhotonTrackStatus", PhotonTrackStatus)
      .SetGuidance("Set the photon track status.")
      .SetParameterName("PhotonTrackStatus", false)
      .SetDefaultValue("true");
}

TPSimSteppingAction::~TPSimSteppingAction() {}

void TPSimSteppingAction::CheckBoundaryStatus(const G4Step *aStep, TPSimEventAction *evtac)
{
  G4OpBoundaryProcessStatus boundaryStatus = Undefined;
  G4OpBoundaryProcess *boundary = NULL;

  // find the boundary process only once
  if (!boundary)
  {
    G4ProcessManager *pm = aStep->GetTrack()->GetDefinition()->GetProcessManager();
    G4int nprocesses = pm->GetProcessListLength();
    G4ProcessVector *pv = pm->GetProcessList();
    G4int i;
    for (i = 0; i < nprocesses; i++)
    {
      if ((*pv)[i]->GetProcessName() == "OpBoundary")
      {
        boundary = (G4OpBoundaryProcess *)(*pv)[i];
        break;
      }
    }
  }

  boundaryStatus = boundary->GetStatus();

  if (endproc == "OpAbsorption")
  {
    if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "ZnS")
    {
      evtac->CountBulkAbsZnS();
    }
    else
    {
      evtac->CountBulkAbsSc();
    }
    if (VerbosityLevel > 1)
      G4cout << "Photon BulkAbsorbed" << G4endl;
    // evtac->FillFiberAngleCreation(evtac->GetPhotonCreationAngle());
  }

  if (endproc == "OpRayleigh")
  {
    //((TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation()))->CountRayleighScattering();
    // G4cout << "Rayleigh scattering" << G4endl;
    // G4cout << "Number of scattering = " << ((ENLOpticalSimTrackInformation*) (aStep->GetTrack()->GetUserInformation()))->GetRayleigh() << G4endl;
  }

  else if (partname == "opticalphoton" && endproc != "Transportation" && endproc != "OpAbsorption" && endproc != "G4FSMP")
    G4cout << endproc << G4endl;

  if (aStep->GetPostStepPoint()->GetStepStatus() == fGeomBoundary)
  {
    if (VerbosityLevel > 1)
      G4cout << "Boundary Status = " << boundaryStatus << G4endl;

    switch (boundaryStatus)
    {
    case Detection:
      evtac->CountDetected();
      evtac->FillPhotonDetectorPositionX(z);
      evtac->FillPhotonDetectorPositionY(y);
      evtac->FillPhotonDetectorPositionZ(z);
      evtac->FillPhotonMomentumX(px);
      evtac->FillPhotonMomentumY(py);
      evtac->FillPhotonMomentumZ(pz);
      evtac->FillBirthLambda(evtac->GetPhotonCreationLambda());
      evtac->FillPhotonTime(aStep->GetPostStepPoint()->GetGlobalTime() / ns);
      evtac->FillPhotonTotalLength(aStep->GetTrack()->GetTrackLength() / mm + evtac->GetTrackLengthFastSimulated());
      evtac->FillFiberAngleDetection(angle / deg);
      evtac->FillFiberAngleCreation(evtac->GetPhotonCreationAngle());
      // evtac->FillPhotonTrajectoryNStep(evtac->GetPhotonTrajectoryNStep());
      // evtac->ClearPhotonTrajectoryNStep();
      // evtac->FillPhotonFinalState(4);

      if (r > 0.5)
      {
        // evtac->FillFiberAngleCreation(evtac->GetPhotonCreationAngle());
        // evtac->FillFiberAngleDetection(angle/deg);
      }

      if (VerbosityLevel > 1)
      {
        G4cout << "Photon detecté" << G4endl;
        G4cout << "angle detection = " << angle / deg << G4endl;
        G4cout << "N detecté = " << evtac->GetDetected() << G4endl;
      }

      break;

    case Absorption: // used to get the number TRANSMITTED!!
      // if (theTrack->GetNextVolume()->GetName()=="Photocathode")
      if (theTrack->GetNextVolume()->GetName() == "Objectif")
      {
        evtac->CountFailed();
        // evtac->FillPhotonTrajectoryNStep(evtac->GetPhotonTrajectoryNStep());
        // evtac->ClearPhotonTrajectoryNStep();
        // evtac->FillPhotonFinalState(3);
        // evtac->FillFiberAngleCreation(evtac->GetPhotonCreationAngle());

        if (VerbosityLevel > 1)
        {
          G4cout << "Photon failed" << G4endl;
          G4cout << "N failed = " << evtac->GetFailed() << G4endl;
        }
      }
      else
      { // if not bulk, transmitted, or detected...it must be surface!
        evtac->CountAbsorbed();
        // evtac->FillPhotonTrajectoryNStep(evtac->GetPhotonTrajectoryNStep());
        // evtac->ClearPhotonTrajectoryNStep();
        // evtac->FillPhotonFinalState(0);
        // evtac->FillFiberAngleCreation(evtac->GetPhotonCreationAngle());

        if (VerbosityLevel > 1)
        {
          G4cout << "Photon surface absorbed" << G4endl;
          G4cout << "N absorbed = " << evtac->GetAbsorbed() << G4endl;
        }
      }
      break;

    case Undefined:
      if (VerbosityLevel > 1)
        G4cout << "Undefined Boundary Process!" << G4endl;
      break;

    case NoRINDEX:
      evtac->CountEscaped();
      // evtac->FillPhotonTrajectoryNStep(evtac->GetPhotonTrajectoryNStep());
      // evtac->ClearPhotonTrajectoryNStep();
      // evtac->FillPhotonFinalState(2);
      // evtac->FillFiberAngleCreation(evtac->GetPhotonCreationAngle());

      if (VerbosityLevel > 1)
      {
        G4cout << "count escaped" << G4endl;
        G4cout << "N escaped = " << evtac->GetEscaped() << G4endl;
      }
      break;

    // if we have any kind of reflections, count them
    case LambertianReflection:
      if (VerbosityLevel > 1)
        G4cout << "Reflection L" << G4endl;
      break;

    case FresnelRefraction:
      if (VerbosityLevel > 1)
        G4cout << "Fresnel Refraction" << G4endl;
      break;

    case FresnelReflection:
      if (VerbosityLevel > 1)
        G4cout << "Fresnel Reflection" << G4endl;
      break;

    case LobeReflection:
      if (VerbosityLevel > 1)
        G4cout << "Reflection Lobe" << G4endl;
      break;

    case SpikeReflection:
      //((TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation()))->CountReflections();
      if (VerbosityLevel > 1)
        G4cout << "Reflection" << G4endl;
      break;

    case TotalInternalReflection:
      //((TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation()))->CountTotalInternalReflections();
      if (VerbosityLevel > 1)
        G4cout << "Reflection totale" << G4endl;
      break;

    default:
      break;
    }
  }
}

void TPSimSteppingAction::KillPhotonAngleCondition(const G4Step *aStep, TPSimEventAction *evtac)
{
  if (angle / deg > 39 && angle / deg < 141 && endproc != "OpAbsorption" && VolumeNamePostStep == "Vacuum")
  {
    theTrack->SetTrackStatus(fStopAndKill);
    evtac->CountBulkAbsSc();
    if (VerbosityLevel > 1)
      G4cout << "ABSORBED" << G4endl;
  }
}

void TPSimSteppingAction::KillPhotonStuckCondition(const G4Step *aStep, TPSimEventAction *evtac)
{
  theTrack->SetTrackStatus(fStopAndKill);
  evtac->CountBulkAbsSc();
  if (VerbosityLevel > 1)
    G4cout << "ABSORBED" << G4endl;
}

void TPSimSteppingAction::CountScintillation(const G4Step *aStep, TPSimEventAction *evtac)
{
  if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "ZnS")
  {
    evtac->CountScintillationZnS();
    if (VerbosityLevel > 1)
      G4cout << " Photon Scintillation from ZnS!!!" << G4endl;
  }

  if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator" || aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Core_Fiber")
  {
    evtac->CountScintillationSc();
    if (VerbosityLevel > 1)
      G4cout << " Photon Scintillation from Sc!!!" << G4endl;
  }
}

void TPSimSteppingAction::CountCerenkov(const G4Step *aStep, TPSimEventAction *evtac)
{
  if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "ZnS")
  {
    evtac->CountCerenkovZnS();
  }
  if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator")
  {
    evtac->CountCerenkovSc();
  }
  if (VerbosityLevel > 1)
    G4cout << " Photon Cerenkov !!!" << G4endl;
}

void TPSimSteppingAction::SetPhotonBirthInformation(const G4Step *aStep, TPSimEventAction *evtac)
{
  evtac->SetPhotonCreationAngle(angle / deg);
  evtac->SetPhotonCreationLambda(1240 / (theTrack->GetTotalEnergy() / eV));
  evtac->SetTrackLengthFastSimulated(0);
  // evtac->FillFiberAngleCreation(angle/deg);

  KillPhotonAngleCondition(aStep, evtac);
}

void TPSimSteppingAction::FillLensPosition(TPSimEventAction *evtac)
{
  evtac->FillPhotonLensPositionX(x);
  evtac->FillPhotonLensPositionY(y);
  if (VerbosityLevel > 2)
  {
    G4cout << "Position X Lens = " << x << G4endl;
    G4cout << "Position Y Lens = " << y << G4endl;
  }
}

void TPSimSteppingAction::FillExitFiberPosition(TPSimEventAction *evtac)
{
  if (VolumeNamePreStep == "Core_Fiber" || VolumeNamePreStep == "Inner_Cladding_Fiber" || VolumeNamePreStep == "Outer_Cladding_Fiber" || VolumeNamePreStep == "Holder_Fiber")
  {
    evtac->FillPhotonExitLightPositionX(x);
    evtac->FillPhotonExitLightPositionY(y);
  }

  if (VerbosityLevel > 2)
  {
    G4cout << "Position X Exit Light = " << x << G4endl;
    G4cout << "Position Y Exit Light = " << y << G4endl;
  }
}

void TPSimSteppingAction::SetInitialInformations(const G4Step *aStep, TPSimEventAction *evtac)
{
  evtac->SetEstartTP(aStep->GetPreStepPoint()->GetKineticEnergy() / MeV);
  evtac->SetIncidentE(aStep->GetPreStepPoint()->GetKineticEnergy() / keV);
  evtac->SetParticuleID(partID);
}

void TPSimSteppingAction::SetTPInformations(const G4Step *aStep, TPSimEventAction *evtac)
{
  evtac->SetTPPositionX(x);
  evtac->SetTPPositionY(y);
  evtac->SetTPPositionZ(z);
  evtac->SetTPTime(aStep->GetPostStepPoint()->GetGlobalTime() / ns);
}

void TPSimSteppingAction::UserSteppingAction(const G4Step *aStep)
{

  // ███████╗██╗░░░██╗███╗░░██╗░█████╗░████████╗░░░░░░░██╗██╗░░░██╗░█████╗░██████╗░░░░
  // ██╔════╝██║░░░██║████╗░██║██╔══██╗╚══██╔══╝░░░░░░██╔╝██║░░░██║██╔══██╗██╔══██╗░░░
  // █████╗░░██║░░░██║██╔██╗██║██║░░╚═╝░░░██║░░░░░░░░██╔╝░╚██╗░██╔╝███████║██████╔╝░░░
  // ██╔══╝░░██║░░░██║██║╚████║██║░░██╗░░░██║░░░░░░░██╔╝░░░╚████╔╝░██╔══██║██╔══██╗░░░
  // ██║░░░░░╚██████╔╝██║░╚███║╚█████╔╝░░░██║░░░██╗██╔╝░░░░░╚██╔╝░░██║░░██║██║░░██║██╗
  // ╚═╝░░░░░░╚═════╝░╚═╝░░╚══╝░╚════╝░░░░╚═╝░░░╚═╝╚═╝░░░░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝

  theTrack = aStep->GetTrack();
  partname = aStep->GetTrack()->GetDefinition()->GetParticleName();
  partID = aStep->GetTrack()->GetDefinition()->GetPDGEncoding();
  TPSimRunAction *runac = (TPSimRunAction *)(G4RunManager::GetRunManager()->GetUserRunAction());
  G4EventManager *evtman = G4EventManager::GetEventManager();
  TPSimEventAction *evtac = (TPSimEventAction *)evtman->GetUserEventAction();
  endproc = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
  Parent_ID = aStep->GetTrack()->GetParentID();
  StepNo = aStep->GetTrack()->GetCurrentStepNumber();

  x = aStep->GetTrack()->GetPosition().x();
  xpre = aStep->GetPreStepPoint()->GetPosition().x();
  y = aStep->GetTrack()->GetPosition().y();
  z = aStep->GetTrack()->GetPosition().z();
  zpre = aStep->GetPreStepPoint()->GetPosition().z();
  px = aStep->GetPreStepPoint()->GetMomentumDirection().x();
  py = aStep->GetPreStepPoint()->GetMomentumDirection().y();
  pz = aStep->GetPreStepPoint()->GetMomentumDirection().z();
  r = sqrt(x * x + y * y);
  angle = acos((x - xpre) / aStep->GetStepLength());
  VolumeNamePreStep = aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName();
  VolumeNamePostStep = aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName();
  time = aStep->GetPostStepPoint()->GetGlobalTime() / ns;
  polarisation = theTrack->GetPolarization();
  // TPSimTrackInformation *trackInformation = (TPSimTrackInformation*)theTrack->GetUserInformation();
  // TPSimTrackInformation* info = (TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation());

  // ░█████╗░██████╗░████████╗██╗░█████╗░░█████╗░██╗░░░░░  ██████╗░░█████╗░██████╗░████████╗
  // ██╔══██╗██╔══██╗╚══██╔══╝██║██╔══██╗██╔══██╗██║░░░░░  ██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝
  // ██║░░██║██████╔╝░░░██║░░░██║██║░░╚═╝███████║██║░░░░░  ██████╔╝███████║██████╔╝░░░██║░░░
  // ██║░░██║██╔═══╝░░░░██║░░░██║██║░░██╗██╔══██║██║░░░░░  ██╔═══╝░██╔══██║██╔══██╗░░░██║░░░
  // ╚█████╔╝██║░░░░░░░░██║░░░██║╚█████╔╝██║░░██║███████╗  ██║░░░░░██║░░██║██║░░██║░░░██║░░░
  // ░╚════╝░╚═╝░░░░░░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚═╝╚══════╝  ╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░

  if (partname == "opticalphoton")
  {
    if (PhotonTrackStatus == false)
      theTrack->SetTrackStatus(fStopAndKill);
    if (StepNo == 1)
    {
      SetPhotonBirthInformation(aStep, evtac);
      if (aStep->GetTrack()->GetCreatorProcess()->GetProcessName() == "Scintillation")
        CountScintillation(aStep, evtac);
      if (aStep->GetTrack()->GetCreatorProcess()->GetProcessName() == "Cerenkov")
        CountCerenkov(aStep, evtac);
    }
    if (StepNo > 1000)
      KillPhotonStuckCondition(aStep, evtac);
    // if (VolumeNamePostStep == "Lens")
    //   FillLensPosition(evtac);
    // if (VolumeNamePostStep == "Vacuum" && z > 0)
    //   FillExitFiberPosition(evtac);

    CheckBoundaryStatus(aStep, evtac);
  }

  // TPSimTrackInformation *info = static_cast<TPSimTrackInformation *>(aStep->GetTrack()->GetUserInformation());
  //  if (!info && partname == "opticalphoton")
  //  {
  //    G4Exception("TPSimTrackInformation", "NoTrackInfo",
  //                FatalException, "No User Information available for this track!");
  //  }

  if (VerbosityLevel > 0)
  {
    G4cout << "x = " << x << G4endl;
    G4cout << "y = " << y << G4endl;
    G4cout << "z = " << z << G4endl;
    G4cout << "z pre = " << zpre << G4endl;
    G4cout << "px = " << px << G4endl;
    G4cout << "py = " << py << G4endl;
    G4cout << "pz = " << pz << G4endl;
    G4cout << "polarisation = " << polarisation << G4endl;
    G4cout << "angle = " << angle / deg << G4endl;
    G4cout << "Time = " << time << " ns" << G4endl;
  }

  if (VerbosityLevel > 1)
  {
    int abs = evtac->GetBulkAbsSc();
    int esc = evtac->GetEscaped();
    int failed = evtac->GetFailed();
    int det = evtac->GetDetected();
    int tot = abs + esc + failed + det;

    G4cout << "N abs = " << abs << G4endl;
    G4cout << "N esc = " << esc << G4endl;
    G4cout << "N failed = " << failed << G4endl;
    G4cout << "N det = " << det << G4endl;
    G4cout << "N TOT = " << tot << G4endl;
    G4cout << "N Sc actuel = " << evtac->GetScintillationSc() << G4endl;
  }

  // ███████╗███╗░░░███╗  ██████╗░░█████╗░██████╗░████████╗
  // ██╔════╝████╗░████║  ██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝
  // █████╗░░██╔████╔██║  ██████╔╝███████║██████╔╝░░░██║░░░
  // ██╔══╝░░██║╚██╔╝██║  ██╔═══╝░██╔══██║██╔══██╗░░░██║░░░
  // ███████╗██║░╚═╝░██║  ██║░░░░░██║░░██║██║░░██║░░░██║░░░
  // ╚══════╝╚═╝░░░░░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░

  if (Parent_ID == 0)
  {
    if (StepNo == 1)
      SetInitialInformations(aStep, evtac);
    // Be careful here !!! If Zns in here, put ZnS. If not, put Scintillator or Core_Fiber!!!!
    if (aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator" && evtac->GetTPPositionZ() == 0)
      SetTPInformations(aStep, evtac);
    if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "ZnS")
      evtac->AddEdepZnS(aStep->GetTotalEnergyDeposit() / keV);
    if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator") evtac->AddEdepSc(aStep->GetTotalEnergyDeposit() / keV);  
    if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Core_Fiber")
      evtac->AddEdepSc(aStep->GetTotalEnergyDeposit() / keV);

    if (((aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator") || (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "ZnS") || (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Core_Fiber")) && ((aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator") || (aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "ZnS") || (aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "Core_Fiber")) && partname != "opticalphoton")
    {
      evtac->AddTrackLength(aStep->GetTrack()->GetStepLength() / mm);
      evtac->AddEdepTP(aStep->GetTotalEnergyDeposit() / keV);
    }
  }

  if (aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "World")
  {
    theTrack->SetTrackStatus(fStopAndKill);
  }
}
