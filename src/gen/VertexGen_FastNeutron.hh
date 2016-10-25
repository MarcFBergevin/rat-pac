// RAT::VertexGen_FastNeutron
//

/** @class RAT::VertexGen_FastNeutron
 *
 * Vertex Generator - events for external fast neutron type
 *
 * @author Jeanne Wilson <j.wilson2@physics.ox.ac.uk>
 *
 * first version : 18-July-2008
 * @author Marc Bergevin <bergevin1@llnl.gov>
 *
 * This vertex generator was based on the template from Jeanne Wilson and adapted for external fast-
 * neutrons. One of the assumption made is that the flux emmited from the wall follow the Mei and
 * Hime formulation. A zeroth order assumption is that the neutron angle from the muon track are 
 * taken from the average muon direction which is (0,0,-1). This assumption will need to be 
 * revisited at a later stage.
 */
#ifndef __RAT_VertexGen_FastNeutron__
#define __RAT_VertexGen_FastNeutron__

#include <RAT/GLG4VertexGen.hh>
#include "RAT/DB.hh"
#include <RAT/FastNeutronMessenger.hh>

#include <G4Event.hh>
#include <G4ThreeVector.hh>
#include <globals.hh>
#include <vector>

namespace RAT {
    
    class VertexGen_FastNeutron : public GLG4VertexGen {
    public:
        
        VertexGen_FastNeutron(const char *arg_dbname="fastneutron");
        virtual 		~VertexGen_FastNeutron();
        /** generate and add new vertex to this event.  Position and
         * time of vertex are offset from 0 by dx and dt.  (These
         * are usually derived from GLG4PosGen and GLG4TimeGen.)
         */
        virtual void 	GeneratePrimaryVertex( G4Event* argEvent,
                                              G4ThreeVector& dx,
                                              G4double dt);
        /** set the state for generator. Format: pname specname
         * where pname is the particle name, and specname is the database FastNeutron name
         */
        virtual void 	SetState( G4String newValues );
        /** return current state */
        virtual 		G4String GetState();
        
        /** Set up the FastNeutron array in memory - create normalised cumulative magnitude for easy**/
        
        void SetDepth(    double AAm =  DDEFAULT);
        void SetEnThreshold(    double EAm =  EDEFAULT);
        
        inline double GetDepth()   {return valueD;} ;
        inline double GetEnThreshold()   {return valueE;} ;
        
    private:
        G4String	_particle;			// name of the particle type
        G4ParticleDefinition* _pDef,*n ;	// particle definition
        G4String	_FastNeutron;			// name of the FastNeutron to use
        
        double valueD,valueE;
        
        FastNeutronMessenger* messenger;

        static const double DDEFAULT = 400;
        static const double EDEFAULT = 10;


    };
    
} // namespace RAT

#endif
