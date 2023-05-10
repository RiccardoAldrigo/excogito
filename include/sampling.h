#ifndef HDR_SAMPLING
#define HDR_SAMPLING

#include <mapping.h>
#include <alignment.h>
#include <hierarchical_clustering.h>

/**
* \class MC_params
* \brief structure that defines a the parameters of Monte Carlo sampling
*/
typedef struct MC_params{
    double t_zero;          /*!< starting effective temperature */
    double decay_time;      /*!< decay parameter */
    int rotmats_period;     /*!< Simulated Annealing steps between two updates of the alignments */
    int MC_steps;           /*!< number of MC steps */
}MC_params;

void my_make_a_move(cg_mapping *old_mapping, cg_mapping *new_mapping, int rem_add[2]);

void simulated_annealing(traj *Trajectory, MC_params *SA_params, int cgnum, int rsd, int verbose, int kl_flag, FILE *f_out_l, int core);	//(!)

void simulated_annealing_spins(traj* Trajectory, MC_params* SA_params, int cgnum, int rsd, int verbose, int kl_flag, FILE* f_out_l, int core);  //(!) ADDED

double tzero_estimation(traj *Trajectory, int cgnum, int rsd, int verbose, int kl_flag, FILE *f_out_l);	//(!)

double tzero_estimation_spins(traj *Trajectory, int cgnum, int rsd, int verbose, int kl_flag, FILE *f_out_l);	//(!) ADDED

#endif
